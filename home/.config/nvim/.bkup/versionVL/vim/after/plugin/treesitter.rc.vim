if !exists('g:loaded_nvim_treesitter')
    echo "Not loaded treesitter"
    finish
endif

nnoremap <leader>c <cmd>lua require('ts_context_commentstring.internal').update_commentstring()<cr>

lua <<EOF

    require'nvim-treesitter.configs'.setup {
        highlight = {
            enable = true,
            disable = {},
        },
        indent = {
            enable = false,
            disable = {},
        },
        ensure_installed = {
            "bash",
            "typescript",
            "javascript",
            "tsx",
            "toml",
            "php",
            "json",
            "yaml",
            "glsl",
            "html",
            "scss",
        },
        context_commentstring = {
            enable = true,
        },
    }

    local parser_config = require "nvim-treesitter.parsers".get_parser_configs()
    parser_config.tsx.used_by = { "javascript", "typescript.tsx" }

EOF
