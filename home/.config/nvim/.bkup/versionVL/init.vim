lua require('plugs')
" lua require('rule')

runtime ./vim/rule.vim
runtime ./vim/quickKeys.vim
runtime ./vim/screws.vim
runtime ./vim/fileType.vim
runtime ./vim/theme.vim
runtime ./vim/tabline.vim
runtime ./vim/plugins/defx.rc.vim

lua << EOF

local lua_plugins = {
	"plugins.lspconfig",
	"plugins.web-devicons",
	"plugins.lualine",
	"plugins.clorizer",
	"plugins.autopairs",
	"plugins.lspsaga",
	"plugins.cmp",
	"plugins.snip",
	"plugins.telescope",
}

for _, v in ipairs(lua_plugins) do
    require(v)
end

EOF
