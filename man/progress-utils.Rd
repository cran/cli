% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/progress-utils.R
\name{cli_progress_num}
\alias{cli_progress_num}
\alias{cli_progress_cleanup}
\title{Progress bar utility functions.}
\usage{
cli_progress_num()

cli_progress_cleanup()
}
\value{
\code{cli_progress_num()} returns an integer scalar.

`cli_progress_cleanup() does not return anything.
}
\description{
Progress bar utility functions.
}
\details{
\code{cli_progress_num()} returns the number of currently
active progress bars. (These do not currently include the progress
bars created in C/C++ code.)

\code{cli_progress_cleanup()} terminates all active progress bars.
(It currently ignores progress bars created in the C/C++ code.)
}
\concept{progress bar}
