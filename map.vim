
-- ✅ SEND TO CODE DROP
vim.api.nvim_create_user_command('Send', function()
  local src = vim.api.nvim_buf_get_name(0)
  if src == '' then
    print('No file to send (buffer has no name)')
    return
  end

  local dest = vim.fn.expand('~/arjun/code_drop/')
  vim.fn.mkdir(dest, 'p')

  -- Copy file
  local cp = vim.fn.system('cp ' .. vim.fn.shellescape(src) .. ' ' .. vim.fn.shellescape(dest))
  if vim.v.shell_error ~= 0 then
    print('Copy error: ' .. cp)
    return
  end

  -- Git add, commit, push
  local fname = vim.fn.fnamemodify(src, ':t')
  local time = os.date("%d-%m-%Y %H:%M")
  local git_cmds = string.format(
    'cd %s && git add . && git commit -m "send: %s [%s]" && git push',
    vim.fn.shellescape(dest), fname, time
  )
  local git_out = vim.fn.system(git_cmds)

  if vim.v.shell_error == 0 then
    print('Sent & pushed: ' .. fname)
  else
    print('Sent but git error: ' .. git_out)
  end
end, {})

vim.cmd('cabbrev send Send')

-- RECEIVE FROM CODE DROP
vim.api.nvim_create_user_command('Receive', function()
  local drop = vim.fn.expand('~/arjun/code_drop/')

  vim.fn.system('cd ' .. vim.fn.shellescape(drop) .. ' && git pull')

  local files = vim.fn.systemlist('ls -p ' .. vim.fn.shellescape(drop) .. ' | grep -v "^\\." | grep -v "/$"')

  if #files == 0 then
    vim.notify('code_drop is empty', vim.log.levels.WARN, { title = "Receive" })
    return
  end

  local buf = vim.api.nvim_create_buf(false, true)
  vim.api.nvim_buf_set_lines(buf, 0, -1, false, files)
  vim.bo[buf].modifiable = false

  local width = 40
  local height = math.min(#files + 2, 15)
  local win = vim.api.nvim_open_win(buf, true, {
    relative = 'editor',
    width = width,
    height = height,
    col = math.floor((vim.o.columns - width) / 2),
    row = math.floor((vim.o.lines - height) / 2),
    style = 'minimal',
    border = 'rounded',
    title = ' code_drop ',
    title_pos = 'center',
  })

  vim.keymap.set('n', '<CR>', function()
    local fname = vim.fn.trim(vim.api.nvim_get_current_line())
    if fname == '' then return end
    vim.fn.system('cat ' .. vim.fn.shellescape(drop .. fname) .. ' | /mnt/c/Windows/System32/clip.exe')
    if vim.v.shell_error == 0 then
      vim.api.nvim_win_close(win, true)
      vim.notify('Copied: ' .. fname, vim.log.levels.INFO, { title = "Receive" })
    else
      vim.notify('Error copying: ' .. fname, vim.log.levels.ERROR, { title = "Receive" })
    end
  end, { buffer = buf })

  vim.keymap.set('n', 'q', function()
    vim.api.nvim_win_close(win, true)
  end, { buffer = buf })

end, {})

vim.cmd('cabbrev receive Receive')

