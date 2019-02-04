## `runtests.sh: 4: Syntax error: word unexpected (expecting "do")`

_Chief. Windows_

If you see this error:

  ```
  Running unit tests:
  : not foundtests.sh: 2: ./tests/runtests.sh:
  ./tests/runtests.sh: 4: ./tests/runtests.sh: Syntax error: word unexpected (expecting "do")
  ```

  You have two options:

  1. Open the file `tests/runtests.sh` in VS Code in whatever subproject folder
     you’re working in, e.g. `fizzbuzz`. Click on the lower right of the screen
     where it says `CRLF`. Choose `LF`. Save the file. Then the error should go
     away.

  2. You can do this from the command line with the `tr` command:

  ```
  cd tests
  cat runtests.sh | tr -d '\r' > runtests.tmp
  mv runtests.tmp runtests.sh
  ```

  The root of the problem is a setting in git that causes all newlines (LF) to
  be converted to carriage-return/newline (CRLF). The script `runtests.sh` is a
  _bash script_ that bash runs, and bash *hates* `\r` and pukes everywhere.

  To cause git to _not_ do newline conversion for future clones, run the
  following:

  ```
  git config --global core.autocrlf false
  ```

## Mac: `malformed object` error when running `make tests`

This is caused by an older version of the `ar` and `ranlib` packages being installed.
Sometimes these conflict with the versions installed with xcode.

If running MacPorts:

```
sudo port selfupdate
sudo port upgrade cctools
```

If running Brew:

```
sudo brew update
sudo brew upgrade gcc
```
