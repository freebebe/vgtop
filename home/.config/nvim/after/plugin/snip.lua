--  vsnip
-- vim.g.vsnip_snippet_dir = '$HOME/.config/nvim/.snippets/'
-- vim.g.vsnip_snippet_dir = vim.fn.stdpath("config") .. "$HOME/.config/nvim/.snippets/"

--  luasnip
require("luasnip/loaders/from_vscode").load({ paths = { "$HOME/.config/nvim/.snippets" } })
