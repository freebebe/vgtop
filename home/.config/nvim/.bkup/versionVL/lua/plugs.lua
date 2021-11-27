-- Install packer (cookie)
-- local install_path = vim.fn.stdpath 'data' .. '/site/pack/packer/start/packer.nvim'
--
-- if vim.fn.empty(vim.fn.glob(install_path)) > 0 then
--   vim.fn.execute('!git clone https://github.com/wbthomason/packer.nvim ' .. install_path)
-- end

vim.api.nvim_exec(
  [[
  augroup Packer
    autocmd!
    autocmd BufWritePost init.lua PackerCompile
  augroup end
]],
  false
)

local packer = require('packer')
local use = packer.use

packer.init({
  -- Some jobs never finish updating when I don't limit the number.
  -- https://github.com/wbthomason/packer.nvim/issues/456
  max_jobs = 20,
})

require('packer').startup(function()
	use ('wbthomason/packer.nvim') -- Package manager

	use ({'tpope/vim-fugitive', opt = true})
	use ({'tpope/vim-rhubarb', opt = true})

	use ('tomtom/tcomment_vim')

    use ('hoob3rt/lualine.nvim')

    use ({'Shougo/defx.nvim', run = ':UpdateRemoteuseins'})
    use ('kristijanhusak/defx-git')

    use ('neovim/nvim-lspconfig')
    use ('glepnir/lspsaga.nvim')

	use ('neovim/nvim-lspconfig') -- use a language server
	use ('hrsh7th/cmp-nvim-lsp')
	use ('hrsh7th/cmp-buffer')
	use ('hrsh7th/nvim-cmp') -- for completion whilst using the language server
	-- use 'github/copilot.vim' -- for AI completion

	use ('L3MON4D3/LuaSnip') -- Snippets plugin

	use ('nvim-lua/popup.nvim')

    use ('Yggdroot/indentLine')

	use ({
	  'nvim-telescope/telescope.nvim',
	  requires =  {'nvim-lua/popup.nvim', 'nvim-lua/plenary.nvim'} 
	})

    use ('kyazdani42/nvim-web-devicons')
    -- use 'blackCauldron7/surround.nvim'

    -- use 'lewis6991/gitsigns.nvim'
    use ({'mg979/vim-visual-multi', branch = 'master'})
    -- use 'windwp/nvim-autopairs'  -- {} () <>
	use ('mattn/emmet-vim')
	use ('norcalli/nvim-colorizer.lua')

	use ({'kchmck/vim-coffee-script', opt = true})


	-- linting
	use ('jose-elias-alvarez/null-ls.nvim')
	use({
	  "jose-elias-alvarez/nvim-lsp-ts-utils",
	  requires = { "neovim/nvim-lspconfig", "nvim-lua/plenary.nvim", "jose-elias-alvarez/null-ls.nvim" },
	})
end)

if os.getenv('INSTALL') then
  goto eof
end
::eof::
