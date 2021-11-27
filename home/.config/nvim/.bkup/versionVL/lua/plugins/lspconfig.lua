--vim.lsp.set_log_level("debug")

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
        '', -- Text
        '', -- Method
        '', -- Function
        '', -- Constructor
        '', -- Field
        '', -- Variable
        '', -- Class
        'ﰮ', -- Interface
        '', -- Module
        '', -- Property
        '', -- Unit
        '', -- Value
        '', -- Enum
        '', -- Keyword
        '﬌', -- Snippet
        '', -- Color
        '', -- File
        '', -- Reference
        '', -- Folder
        '', -- EnumMember
        '', -- Constant
        '', -- Struct
        '', -- Event
        'ﬦ', -- Operator
        '', -- TypeParameter
    }
end

-- nvim-cmp supports additional completion capabilities
local capabilities = require('cmp_nvim_lsp').update_capabilities(
  vim.lsp.protocol.make_client_capabilities()
)

vim.o.completeopt=menuone,noinsert,noselect

nvim_lsp.flow.setup {
    on_attach = on_attach,
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

lspconfig.efm.setup {
    on_attach = on_attach,
    filetypes = { 'javascript', 'javascriptreact', 'json', 'typescript', 'typescriptreact', 'css', 'less', 'scss', 'markdown', 'pandoc' },
    init_options = {
        linters = {
          eslint = {
            command = 'eslint_d',
            rootPatterns = { '.git' },
            debounce = 100,
            args = { '--stdin', '--stdin-filename', '%filepath', '--format', 'json' },
            sourceName = 'eslint_d',
            parseJson = {
              errorsRoot = '[0].messages',
              line = 'line',
              column = 'column',
              endLine = 'endLine',
              endColumn = 'endColumn',
              message = '[eslint] ${message} [${ruleId}]',
              security = 'severity'
            },
            securities = {
              [2] = 'error',
              [1] = 'warning'
            }
          },
        },
        filetypes = {
          javascript = 'eslint',
          javascriptreact = 'eslint',
          typescript = 'eslint',
          typescriptreact = 'eslint',
        },
        formatters = {
          eslint_d = {
            command = 'eslint_d',
            rootPatterns = { '.git' },
            args = { '--stdin', '--stdin-filename', '%filename', '--fix-to-stdout' },
            rootPatterns = { '.git' },
          },
          prettier = {
            command = 'prettier_d_slim',
            rootPatterns = { '.git' },
            -- requiredFiles: { 'prettier.config.js' },
            args = { '--stdin', '--stdin-filepath', '%filename' }
          }
        },
        formatFiletypes = {
          css = 'prettier',
          javascript = 'prettier',
          javascriptreact = 'prettier',
          json = 'prettier',
          scss = 'prettier',
          less = 'prettier',
          typescript = 'prettier',
          typescriptreact = 'prettier',
          json = 'prettier',
          markdown = 'prettier',
          }
      },
    capabilities = capabilities,
}

nvim_lsp.tsserver.setup {
    -- on_attach = on_attach,
    -- filetypes = { "typescript", "typescriptreact", "typescript.tsx" }
    -- filetypes = { "javascript", "javascriptreact", "javascript.jsx", "typescript", "typescriptreact", "typescript.tsx" },
    -- filetypes = { "javascript", "javascriptreact", "javascript.jsx" }
	on_attach = function(client, bufnr)
      -- disable tsserver formatting in favor of null-ls
      client.resolved_capabilities.document_formatting = false
      client.resolved_capabilities.document_range_formatting = false

      local ts_utils = require("nvim-lsp-ts-utils")

      ts_utils.setup({
        debug = false,
        disable_commands = false,
        enable_import_on_completion = true,

        -- import all
        import_all_timeout = 5000, -- ms
        import_all_priorities = {
          buffers = 4, -- loaded buffer names
          buffer_content = 3, -- loaded buffer content
          local_files = 2, -- git files or files with relative path markers
          same_file = 1, -- add to existing import statement
        },
        import_all_scan_buffers = 100,
        import_all_select_source = false,
      })

      -- required to fix code action ranges and filter diagnostics
      ts_utils.setup_client(client)

      -- no default maps, so you may want to define some here
      local opts = { silent = true }
      vim.api.nvim_buf_set_keymap(bufnr, "n", "gs", ":TSLspOrganize<CR>", opts)
      vim.api.nvim_buf_set_keymap(bufnr, "n", "gr", ":TSLspRenameFile<CR>", opts)
      vim.api.nvim_buf_set_keymap(bufnr, "n", "gi", ":TSLspImportAll<CR>", opts)
    end,
    capabilities = capabilities,
}

-- Status config
lsp_status.register_progress()
lsp_status.config({
  status_symbol = "  LSP:",
  indicator_errors = M.signs.Error,
  indicator_warnings = M.signs.Warning,
  indicator_info = M.signs.Information,
  indicator_hint = M.signs.Hint,
  indicator_ok = "✓",
  spinner_frames = { "⣾", "⣽", "⣻", "⢿", "⡿", "⣟", "⣯", "⣷" },
})
