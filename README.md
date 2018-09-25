cli
================


> Helpers for Developing Command Line Interfaces

[![Linux Build Status](https://api.travis-ci.org/r-lib/cli.svg?branch=master)](https://travis-ci.org/r-lib/cli)
[![Windows Build status](https://ci.appveyor.com/api/projects/status/github/r-lib/cli?svg=true)](https://ci.appveyor.com/project/gaborcsardi/cli)
[![](http://www.r-pkg.org/badges/version/cli)](http://www.r-pkg.org/pkg/cli)
[![CRAN RStudio mirror downloads](http://cranlogs.r-pkg.org/badges/cli)](http://www.r-pkg.org/pkg/cli)
[![Coverage Status](https://img.shields.io/codecov/c/github/r-lib/cli/master.svg)](https://codecov.io/github/r-lib/cli?branch=master)

It integrates well with `crayon` for coloring the boxes or their content,
It can draw rules and boxes to make headers or footers in console output,
and tree structures. It includes a set of Unicode characters, with fallbacks
on systems that do not support them.

---

-   [Installation](#installation)
-   [Usage](#usage)
    -   [Unicode characters](#unicode-characters)
    -   [Spinners](#spinners)
    -   [Rules](#rules)
    -   [Boxes](#boxes)
    -   [Trees](#trees)
-   [License](#license)

---

# Installation

Install the stable version from CRAN:

``` r
install.packages("cli")
```

Install the development version from GitHub:

``` r
source("https://install-github.me/r-lib/cli")
```

# Usage

``` r
library(cli)
```

## Unicode characters

Inspired by (and mostly copied from) the
[figures](https://github.com/sindresorhus/figures) JavaScript project.

    #> ✔    tick                      ☐ checkbox_off           
    #> ✖    cross                     ⓧ checkbox_circle_on     
    #> ★    star                      Ⓘ checkbox_circle_off    
    #> ▇    square                    ❓ fancy_question_mark    
    #> ◻    square_small              ≠ neq                    
    #> ◼    square_small_filled       ≥ geq                    
    #> ◯    circle                    ≤ leq                    
    #> ◉    circle_filled             × times                  
    #> ◌    circle_dotted             ▔ upper_block_1          
    #> ◎    circle_double             ▀ upper_block_4          
    #> ⓞ    circle_circle             ▁ lower_block_1          
    #> ⓧ    circle_cross              ▂ lower_block_2          
    #> Ⓘ    circle_pipe               ▃ lower_block_3          
    #> ?⃝   circle_question_mark      ▄ lower_block_4          
    #> ●    bullet                    ▅ lower_block_5          
    #> ․    dot                       ▆ lower_block_6          
    #> ─    line                      ▇ lower_block_7          
    #> ═    double_line               █ lower_block_8          
    #> …    ellipsis                  █ full_block             
    #> …    continue                  ⁰ sup_0                  
    #> ❯    pointer                   ¹ sup_1                  
    #> ℹ    info                      ² sup_2                  
    #> ⚠    warning                   ³ sup_3                  
    #> ☰    menu                      ⁴ sup_4                  
    #> ☺    smiley                    ⁵ sup_5                  
    #> ෴    mustache                  ⁶ sup_6                  
    #> ♥    heart                     ⁷ sup_7                  
    #> ↑    arrow_up                  ⁸ sup_8                  
    #> ↓    arrow_down                ⁹ sup_9                  
    #> ←    arrow_left                ⁻ sup_minus              
    #> →    arrow_right               ⁺ sup_plus               
    #> ◉    radio_on                  ▶ play                   
    #> ◯    radio_off                 ■ stop                   
    #> ☒    checkbox_on               ● record

## Spinners

See `list_spinners()` and `get_spinner()`. From the awesome
[cli-spinners](https://github.com/sindresorhus/cli-spinners#readme)
project.

![](man/figures/spinners.gif)

## Rules

Simple rule

``` r
rule()
```

![](man/figures/rule-1.png)<!-- -->

Double rule

``` r
rule(line = 2)
```

![](man/figures/rule-double-1.png)<!-- -->

Bars

``` r
rule(line = "bar2")
```

![](man/figures/rule-bars-1.png)<!-- -->

``` r
rule(line = "bar5")
```

![](man/figures/rule-bars-2.png)<!-- -->

Left label

``` r
rule(left = "Results")
```

![](man/figures/rule-left-1.png)<!-- -->

Centered label

``` r
rule(center = " * RESULTS * ")
```

![](man/figures/rule-center-1.png)<!-- -->

Colored labels

``` r
rule(center = crayon::red(" * RESULTS * "))
```

![](man/figures/rule-color-label-1.png)<!-- -->

Colored label and line

``` r
rule(center = " * RESULTS * ", col = "red")
```

![](man/figures/rule-color-1.png)<!-- -->

Colored line

``` r
rule(center = " * RESULTS * ", line_col = "red")
```

![](man/figures/rule-color-line-1.png)<!-- -->

Custom line

``` r
rule(center = "TITLE", line = "~")
```

![](man/figures/rule-line-custom-1.png)<!-- -->

More custom line

``` r
rule(center = "TITLE", line = "~-", line_col = "blue")
```

![](man/figures/rule-line-custom-2-1.png)<!-- -->

Even more custom
line

``` r
rule(center = crayon::bgRed(" ", symbol$star, "TITLE", symbol$star, " "),
  line = "\u2582", line_col = "orange")
```

![](man/figures/rule-line-custom-3-1.png)<!-- -->

## Boxes

Default box

``` r
boxx("Hello there!")
```

![](man/figures/box-1.png)<!-- -->

Change border style

``` r
boxx("Hello there!", border_style = "double")
```

![](man/figures/box-border-style-1.png)<!-- -->

Multiple lines

``` r
boxx(c("Hello", "there!"), padding = 1)
```

![](man/figures/box-lines-1.png)<!-- -->

Padding

``` r
boxx("Hello there!", padding = 1)
```

![](man/figures/box-padding-1.png)<!-- -->

``` r
boxx("Hello there!", padding = c(1, 5, 1, 5))
```

![](man/figures/box-padding-2.png)<!-- -->

Margin

``` r
boxx("Hello there!", margin = 1)
```

![](man/figures/box-margin-1.png)<!-- -->

``` r
boxx("Hello there!", margin = c(1, 5, 1, 5))
```

![](man/figures/box-margin-2.png)<!-- -->

``` r
boxx("Hello there!", padding = 1, margin = c(1, 5, 1, 5))
```

![](man/figures/box-margin-3.png)<!-- -->

Floating

``` r
boxx("Hello there!", padding = 1, float = "center")
```

![](man/figures/box-floating-1.png)<!-- -->

``` r
boxx("Hello there!", padding = 1, float = "right")
```

![](man/figures/box-floating-2.png)<!-- -->

Text color

``` r
boxx(crayon::cyan("Hello there!"), padding = 1, float = "center")
```

![](man/figures/box-color-1.png)<!-- -->

Backgorund color

``` r
boxx("Hello there!", padding = 1, background_col = "brown")
```

![](man/figures/box-bgcolor-1.png)<!-- -->

``` r
boxx("Hello there!", padding = 1, background_col = crayon::bgRed)
```

![](man/figures/box-bgcolor-2.png)<!-- -->

Border color

``` r
boxx("Hello there!", padding = 1, border_col = "green")
```

![](man/figures/box-border-color-1.png)<!-- -->

``` r
boxx("Hello there!", padding = 1, border_col = crayon::red)
```

![](man/figures/box-border-color-2.png)<!-- -->

Label alignment

``` r
boxx(c("Hi", "there", "you!"), padding = 1, align = "left")
```

![](man/figures/box-label-align-1.png)<!-- -->

``` r
boxx(c("Hi", "there", "you!"), padding = 1, align = "center")
```

![](man/figures/box-label-align-2.png)<!-- -->

``` r
boxx(c("Hi", "there", "you!"), padding = 1, align = "right")
```

![](man/figures/box-label-align-3.png)<!-- -->

A very customized box

``` r
star <- symbol$star
label <- c(paste(star, "Hello", star), "  there!")
boxx(
  crayon::white(label),
  border_style="round",
  padding = 1,
  float = "center",
  border_col = "tomato3",
  background_col="darkolivegreen"
)
```

![](man/figures/box-customized-1.png)<!-- -->

## Trees

You can specify the tree with a two column data frame, containing the
node ids/labels, and the list of their children.

``` r
data <- data.frame(
  stringsAsFactors = FALSE,
  package = c("processx", "backports", "assertthat", "Matrix",
    "magrittr", "rprojroot", "clisymbols", "prettyunits", "withr",
    "desc", "igraph", "R6", "crayon", "debugme", "digest", "irlba",
    "rcmdcheck", "callr", "pkgconfig", "lattice"),
  dependencies = I(list(
    c("assertthat", "crayon", "debugme", "R6"), character(0),
    character(0), "lattice", character(0), "backports", character(0),
    c("magrittr", "assertthat"), character(0),
    c("assertthat", "R6", "crayon", "rprojroot"),
    c("irlba", "magrittr", "Matrix", "pkgconfig"), character(0),
    character(0), "crayon", character(0), "Matrix",
    c("callr", "clisymbols", "crayon", "desc", "digest", "prettyunits",
      "R6", "rprojroot", "withr"),
    c("processx", "R6"), character(0), character(0)
  ))
)
tree(data, root = "rcmdcheck")
```

![](man/figures/tree-1.png)<!-- -->

An optional third column may contain custom labels. These can be colored
as well:

``` r
data$label <- paste(data$package,
  crayon::blurred(paste0("(", c("2.0.0.1", "1.1.1", "0.2.0", "1.2-11",
    "1.5", "1.2", "1.2.0", "1.0.2", "2.0.0", "1.1.1.9000", "1.1.2",
    "2.2.2", "1.3.4", "1.0.2", "0.6.12", "2.2.1", "1.2.1.9002",
    "1.0.0.9000", "2.0.1", "0.20-35"), ")"))
  )
roots <- ! data$package %in% unlist(data$dependencies)
data$label[roots] <- crayon::cyan(crayon::italic(data$label[roots]))
tree(data, root = "rcmdcheck")
```

![](man/figures/tree-color-1.png)<!-- -->

# License

MIT © RStudio
