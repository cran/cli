# collapsing without formatting, n>3

    Code
      pkgs <- paste0("pkg", 1:5)
      cli_text("Packages: {pkgs}.")
    Message
      Packages: pkg1, pkg2, pkg3, pkg4, and pkg5.

# collapsing without formatting, n<3

    Code
      pkgs <- paste0("pkg", 1:2)
      cli_text("Packages: {pkgs}.")
    Message
      Packages: pkg1 and pkg2.

# collapsing with formatting

    Code
      local({
        cli_div(theme = list(.pkg = list(fmt = function(x) paste0(x, " (P)"))))
        pkgs <- paste0("pkg", 1:5)
        cli_text("Packages: {.pkg {pkgs}}.")
      })
    Message
      Packages: pkg1 (P), pkg2 (P), pkg3 (P), pkg4 (P), and pkg5 (P).

# collapsing with formatting, custom seps

    Code
      local({
        cli_div(theme = list(div = list(`vec-sep` = " ... ")))
        pkgs <- paste0("pkg", 1:5)
        cli_text("Packages: {.pkg {pkgs}}.")
      })
    Message
      Packages: pkg1 ... pkg2 ... pkg3 ... pkg4, and pkg5.

# collapsing a cli_vec

    Code
      pkgs <- cli_vec(paste0("pkg", 1:5), style = list(`vec-sep` = " & ", `vec-last` = " & "))
      cli_text("Packages: {pkgs}.")
    Message
      Packages: pkg1 & pkg2 & pkg3 & pkg4 & pkg5.

# collapsing a cli_vec with styling [plain]

    Code
      local({
        cli_div(theme = list(body = list(`vec-sep` = " ... ")))
        pkgs <- cli_vec(paste0("pkg", 1:5), style = list(`vec-sep` = " & ",
          `vec-last` = " & ", color = "blue"))
        cli_text("Packages: {pkgs}.")
      })
    Message
      Packages: pkg1 & pkg2 & pkg3 & pkg4 & pkg5.

# collapsing a cli_vec with styling [ansi]

    Code
      local({
        cli_div(theme = list(body = list(`vec-sep` = " ... ")))
        pkgs <- cli_vec(paste0("pkg", 1:5), style = list(`vec-sep` = " & ",
          `vec-last` = " & ", color = "blue"))
        cli_text("Packages: {pkgs}.")
      })
    Message
      Packages: [34mpkg1[39m & [34mpkg2[39m & [34mpkg3[39m & [34mpkg4[39m & [34mpkg5[39m.

# head

    Code
      cli_text("{v(0,1)}")
    Message
      
    Code
      cli_text("{v(1,1)}")
    Message
      1
    Code
      cli_text("{v(2,1)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,1)}")
    Message
      1, ...
    Code
      cli_text("{v(4,1)}")
    Message
      1, ...
    Code
      cli_text("{v(0,2)}")
    Message
      
    Code
      cli_text("{v(1,2)}")
    Message
      1
    Code
      cli_text("{v(2,2)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,2)}")
    Message
      1, 2, and 3
    Code
      cli_text("{v(4,2)}")
    Message
      1, 2, ...
    Code
      cli_text("{v(0,3)}")
    Message
      
    Code
      cli_text("{v(1,3)}")
    Message
      1
    Code
      cli_text("{v(2,3)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,3)}")
    Message
      1, 2, and 3
    Code
      cli_text("{v(4,3)}")
    Message
      1, 2, 3, and 4
    Code
      cli_text("{v(0,4)}")
    Message
      
    Code
      cli_text("{v(1,4)}")
    Message
      1
    Code
      cli_text("{v(2,4)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,4)}")
    Message
      1, 2, and 3
    Code
      cli_text("{v(4,4)}")
    Message
      1, 2, 3, and 4
    Code
      cli_text("{v(0,5)}")
    Message
      
    Code
      cli_text("{v(1,5)}")
    Message
      1
    Code
      cli_text("{v(2,5)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,5)}")
    Message
      1, 2, and 3
    Code
      cli_text("{v(4,5)}")
    Message
      1, 2, 3, and 4
    Code
      cli_text("{v(10,5)}")
    Message
      1, 2, 3, 4, 5, ...

# both-ends

    Code
      cli_text("{v(0,1)}")
    Message
      
    Code
      cli_text("{v(1,1)}")
    Message
      1
    Code
      cli_text("{v(2,1)}")
    Message
      1 and 2
    Code
      cli_text("{v(3,1)}")
    Message
      1, 2, and 3
    Code
      cli_text("{v(4,1)}")
    Message
      1, 2, 3, and 4
    Code
      cli_text("{v(5,1)}")
    Message
      1, 2, 3, 4, and 5
    Code
      cli_text("{v(6,1)}")
    Message
      1, 2, 3, ..., 5, and 6
    Code
      cli_text("{v(7,1)}")
    Message
      1, 2, 3, ..., 6, and 7
    Code
      cli_text("{v(10,1)}")
    Message
      1, 2, 3, ..., 9, and 10

# both-ends with formatting [plain]

    Code
      cli_text("{.val {v(0,1)}}")
    Message
      
    Code
      cli_text("{.val {v(1,1)}}")
    Message
      1
    Code
      cli_text("{.val {v(2,1)}}")
    Message
      1 and 2
    Code
      cli_text("{.val {v(3,1)}}")
    Message
      1, 2, and 3
    Code
      cli_text("{.val {v(4,1)}}")
    Message
      1, 2, 3, and 4
    Code
      cli_text("{.val {v(5,1)}}")
    Message
      1, 2, 3, 4, and 5
    Code
      cli_text("{.val {v(6,1)}}")
    Message
      1, 2, 3, ..., 5, and 6
    Code
      cli_text("{.val {v(7,1)}}")
    Message
      1, 2, 3, ..., 6, and 7
    Code
      cli_text("{.val {v(10,1)}}")
    Message
      1, 2, 3, ..., 9, and 10
    Code
      cli_text("{.val {v(10,6)}}")
    Message
      1, 2, 3, 4, ..., 9, and 10
    Code
      cli_text("{.val {v(10,10)}}")
    Message
      1, 2, 3, 4, 5, 6, 7, 8, 9, and 10
    Code
      cli_text("{.val {v(11,10)}}")
    Message
      1, 2, 3, 4, 5, 6, 7, 8, 9, 10, and 11

# both-ends with formatting [ansi]

    Code
      cli_text("{.val {v(0,1)}}")
    Message
      
    Code
      cli_text("{.val {v(1,1)}}")
    Message
      [34m1[39m
    Code
      cli_text("{.val {v(2,1)}}")
    Message
      [34m1[39m and [34m2[39m
    Code
      cli_text("{.val {v(3,1)}}")
    Message
      [34m1[39m, [34m2[39m, and [34m3[39m
    Code
      cli_text("{.val {v(4,1)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, and [34m4[39m
    Code
      cli_text("{.val {v(5,1)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, [34m4[39m, and [34m5[39m
    Code
      cli_text("{.val {v(6,1)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, ..., [34m5[39m, and [34m6[39m
    Code
      cli_text("{.val {v(7,1)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, ..., [34m6[39m, and [34m7[39m
    Code
      cli_text("{.val {v(10,1)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, ..., [34m9[39m, and [34m10[39m
    Code
      cli_text("{.val {v(10,6)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, [34m4[39m, ..., [34m9[39m, and [34m10[39m
    Code
      cli_text("{.val {v(10,10)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, [34m4[39m, [34m5[39m, [34m6[39m, [34m7[39m, [34m8[39m, [34m9[39m, and [34m10[39m
    Code
      cli_text("{.val {v(11,10)}}")
    Message
      [34m1[39m, [34m2[39m, [34m3[39m, [34m4[39m, [34m5[39m, [34m6[39m, [34m7[39m, [34m8[39m, [34m9[39m, [34m10[39m, and [34m11[39m

