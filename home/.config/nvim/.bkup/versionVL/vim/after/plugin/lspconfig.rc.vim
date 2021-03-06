if !exists('g:lspconfig') | finish | endif

lua << EOF
--vim.lsp.set_log_level("debug")
EOF

lua << EOF
local nvim_lsp = require('lspconfig')
local protocol = require'vim.lsp.protocol'

-- Use an on_attach function to only map the following keys 
-- after the language server attaches to the current buffer
local on_attach = function(client, bufnr)
    local function buf_set_keymap(...) vim.api.nvim_buf_set_keymap(bufnr, ...) end
    local function buf_set_option(...) vim.api.nvim_buf_set_option(bufnr, ...) end

    --Enable completion triggered by <c-x><c-o>
    buf_set_option('omnifunc', 'v:lua.vim.lsp.omnifunc')

    -- Mappings.
    local opts = { noremap=true, silent=true }

    -- See `:help vim.lsp.*` for documentation on any of the below functions
    buf_set_keymap('n', 'gD', '<Cmd>lua vim.lsp.buf.declaration()<CR>', opts)
    buf_set_keymap('n', 'gd', '<Cmd>lua vim.lsp.buf.definition()<CR>', opts)
    --buf_set_keymap('n', 'K', '<Cmd>lua vim.lsp.buf.hover()<CR>', opts)
    buf_set_keymap('n', 'gi', '<cmd>lua vim.lsp.buf.implementation()<CR>', opts)
    --buf_set_keymap('i', '<C-k>', '<cmd>lua vim.lsp.buf.signature_help()<CR>', opts)
    buf_set_keymap('n', '<space>wa', '<cmd>lua vim.lsp.buf.add_workspace_folder()<CR>', opts)
    buf_set_keymap('n', '<space>wr', '<cmd>lua vim.lsp.buf.remove_workspace_folder()<CR>', opts)
    buf_set_keymap('n', '<space>wl', '<cmd>lua print(vim.inspect(vim.lsp.buf.list_workspace_folders()))<CR>', opts)
    buf_set_keymap('n', '<space>D', '<cmd>lua vim.lsp.buf.type_definition()<CR>', opts)
    buf_set_keymap('n', '<space>rn', '<cmd>lua vim.lsp.buf.rename()<CR>', opts)
    buf_set_keymap('n', '<space>ca', '<cmd>lua vim.lsp.buf.code_action()<CR>', opts)
    buf_set_keymap('n', 'gr', '<cmd>lua vim.lsp.buf.references()<CR>', opts)
    buf_set_keymap('n', '<space>e', '<cmd>lua vim.lsp.diagnostic.show_line_diagnostics()<CR>', opts)
    --buf_set_keymap('n', '<C-j>', '<cmd>lua vim.lsp.diagnostic.goto_prev()<CR>', opts)
    buf_set_keymap('n', '<S-C-j>', '<cmd>lua vim.lsp.diagnostic.goto_next()<CR>', opts)
    buf_set_keymap('n', '<space>q', '<cmd>lua vim.lsp.diagnostic.set_loclist()<CR>', opts)
    buf_set_keymap("n", "<space>f", "<cmd>lua vim.lsp.buf.formatting()<CR>", opts)

    -- formatting
    if client.name == 'denols' then
        client.resolved_capabilities.document_formatting = false
    end


    if client.resolved_capabilities.document_formatting then
        vim.api.nvim_command [[augroup Format]]
        vim.api.nvim_command [[autocmd! * <buffer>]]
        vim.api.nvim_command [[autocmd BufWritePre <buffer> lua vim.lsp.buf.formatting_seq_sync()]]
        vim.api.nvim_command [[augroup END]]
    end


    protocol.SymbolKind = { }
    protocol.CompletionItemKind = {
        '???', -- Text
        '???', -- Method
        '???', -- Function
        '???', -- Constructor
        '???', -- Field
        '???', -- Variable
        '???', -- Class
        '???', -- Interface
        '???', -- Module
        '???', -- Property
        '???', -- Unit
        '???', -- Value
        '???', -- Enum
        '???', -- Keyword
        '???', -- Snippet
        '???', -- Color
        '???', -- File
        '???', -- Reference
        '???', -- Folder
        '???', -- EnumMember
        '???', -- Constant
        '???', -- Struct
        '???', -- Event
        '???', -- Operator
        '???', -- TypeParameter
    }
end

-- nvim-cmp supports additional completion capabilities
local capabilities = require('cmp_nvim_lsp').update_capabilities(
  vim.lsp.protocol.make_client_capabilities()
)

nvim_lsp.flow.setup {
    on_attach = on_attach,
    capabilities = capabilities,
}

nvim_lsp.denols.setup {
    on_attach = on_attach,
    filetypes = { "javascript", "javascriptreact", "javascript.jsx", "typescript", "typescriptreact", "typescript.tsx" },
    -- filetypes = { "typescript", "typescriptreact", "typescript.tsx" },
    capabilities = capabilities,
}



--nvim_lsp.efm.setup {
--     filetypes = { 'javascript', 'javascriptreact', 'json', 'typescript', 'typescriptreact', 'css', 'less', 'scss', 'markdown', 'pandoc' },
--     init_options = {
--         linters = {
--           eslint = {
--             command = 'eslint_d',
--             rootPatterns = { '.git' },
--             debounce = 100,
--             args = { '--stdin', '--stdin-filename', '%filepath', '--format', 'json' },
--             sourceName = 'eslint_d',
--             parseJson = {
--               errorsRoot = '[0].messages',
--               line = 'line',
--               column = 'column',
--               endLine = 'endLine',
--               endColumn = 'endColumn',
--               message = '[eslint] ${message} [${ruleId}]',
--               security = 'severity'
--             },
--             securities = {
--               [2] = 'error',
--               [1] = 'warning'
--             }
--           },
--         },
--         filetypes = {
--           javascript = 'eslint',
--           javascriptreact = 'eslint',
--           typescript = 'eslint',
--           typescriptreact = 'eslint',
--         },
--         formatters = {
--           eslint_d = {
--             command = 'eslint_d',
--             rootPatterns = { '.git' },
--             args = { '--stdin', '--stdin-filename', '%filename', '--fix-to-stdout' },
--             rootPatterns = { '.git' },
--           },
--           prettier = {
--             command = 'prettier_d_slim',
--             rootPatterns = { '.git' },
--             -- requiredFiles: { 'prettier.config.js' },
--             args = { '--stdin', '--stdin-filepath', '%filename' }
--           }
--         },
--         formatFiletypes = {
--           css = 'prettier',
--           javascript = 'prettier',
--           javascriptreact = 'prettier',
--           json = 'prettier',
--           scss = 'prettier',
--           less = 'prettier',
--           typescript = 'prettier',
--           typescriptreact = 'prettier',
--           json = 'prettier',
--           markdown = 'prettier',
--           }
--       }
-- }

--
nvim_lsp.cssls.setup {
    on_attach = on_attach,
    cmd = { "vscode-css-languageserver", "--stdio" },
    formatters = {
        prettier = {
            command = 'prettier',
            args = { '--stdin-filepath', '%filename' },
        },
    },
    filetypes = { "css", "scss", "less" },
    formatFiletypes = {
        css = 'prettier',
        scss = 'prettier',
        less = 'prettier',
    },
    capabilities = capabilities,
}

--lspconfig.efm.setup {
--     on_attach = on_attach,
--     filetypes = { 'javascript', 'javascriptreact', 'json', 'typescript', 'typescriptreact', 'css', 'less', 'scss', 'markdown', 'pandoc' },
--     init_options = {
--         linters = {
--           eslint = {
--             command = 'eslint_d',
--             rootPatterns = { '.git' },
--             debounce = 100,
--             args = { '--stdin', '--stdin-filename', '%filepath', '--format', 'json' },
--             sourceName = 'eslint_d',
--             parseJson = {
--               errorsRoot = '[0].messages',
--               line = 'line',
--               column = 'column',
--               endLine = 'endLine',
--               endColumn = 'endColumn',
--               message = '[eslint] ${message} [${ruleId}]',
--               security = 'severity'
--             },
--             securities = {
--               [2] = 'error',
--               [1] = 'warning'
--             }
--           },
--         },
--         filetypes = {
--           javascript = 'eslint',
--           javascriptreact = 'eslint',
--           typescript = 'eslint',
--           typescriptreact = 'eslint',
--         },
--         formatters = {
--           eslint_d = {
--             command = 'eslint_d',
--             rootPatterns = { '.git' },
--             args = { '--stdin', '--stdin-filename', '%filename', '--fix-to-stdout' },
--             rootPatterns = { '.git' },
--           },
--           prettier = {
--             command = 'prettier_d_slim',
--             rootPatterns = { '.git' },
--             -- requiredFiles: { 'prettier.config.js' },
--             args = { '--stdin', '--stdin-filepath', '%filename' }
--           }
--         },
--         formatFiletypes = {
--           css = 'prettier',
--           javascript = 'prettier',
--           javascriptreact = 'prettier',
--           json = 'prettier',
--           scss = 'prettier',
--           less = 'prettier',
--           typescript = 'prettier',
--           typescriptreact = 'prettier',
--           json = 'prettier',
--           markdown = 'prettier',
--           }
--       }
-- }

--nvim_lsp.jsonls.setup{
--     on_attach = on_attach,
--     cmd = { "vscode-json-languageserver", "--stdio" },
--     filetypes = { 'json' }
-- }

--nvim_lsp.texlab.setup{
--     on_attach = on_attach,
--     cmd = { "texlab" },
--     filetypes = { "tex", "bib" }
-- }


--nvim_lsp.tsserver.setup {
--     on_attach = on_attach,
--     -- filetypes = { "typescript", "typescriptreact", "typescript.tsx" }
--     filetypes = { "javascript", "javascriptreact", "javascript.jsx", "typescript", "typescriptreact", "typescript.tsx" },
--     -- filetypes = { "javascript", "javascriptreact", "javascript.jsx" }
--     init_options = {
--         linters = {
--           eslint = {
--             command = 'eslint_d',
--             rootPatterns = { '.git' },
--             debounce = 100,
--             args = { '--stdin', '--stdin-filename', '%filepath', '--format', 'json' },
--             sourceName = 'eslint_d',
--             parseJson = {
--               errorsRoot = '[0].messages',
--               line = 'line',
--               column = 'column',
--               endLine = 'endLine',
--               endColumn = 'endColumn',
--               message = '[eslint] ${message} [${ruleId}]',
--               security = 'severity'
--             },
--             securities = {
--               [2] = 'error',
--               [1] = 'warning'
--             }
--           },
--         },
--         filetypes = {
--           javascript = 'eslint',
--           javascriptreact = 'eslint',
--           typescript = 'eslint',
--           typescriptreact = 'eslint',
--         },
--         formatters = {
--           eslint_d = {
--             command = 'eslint_d',
--             args = { '--stdin', '--stdin-filename', '%filename', '--fix-to-stdout' },
--             rootPatterns = { '.git' },
--           },
--           prettier = {
--             command = 'prettier',
--             args = { '--stdin-filepath', '%filename' }
--           }
--         },
--         formatFiletypes = {
--           javascript = 'eslint_d',
--           javascriptreact = 'eslint_d',
--           typescript = 'eslint_d',
--           typescriptreact = 'eslint_d',
--         }
--     }
-- }


--nvim_lsp.rls.setup {
--     on_attach = on_attach,
--     filetypes = { "rust" }
-- }

--nvim_lsp.volar.setup{
--     on_attach = on_attach,
--     cmd = { "volar-server", "--stdio" },
--     filetypes = { "vue" }
-- }


EOF

