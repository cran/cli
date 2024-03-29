% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/tty.R
\name{ansi_hide_cursor}
\alias{ansi_hide_cursor}
\alias{ansi_show_cursor}
\alias{ansi_with_hidden_cursor}
\title{Hide/show cursor in a terminal}
\usage{
ansi_hide_cursor(stream = "auto")

ansi_show_cursor(stream = "auto")

ansi_with_hidden_cursor(expr, stream = "auto")
}
\arguments{
\item{stream}{The stream to inspect or manipulate, an R connection
object. It can also be a string, one of \code{"auto"}, \code{"message"},
\code{"stdout"}, \code{"stderr"}. \code{"auto"} will select \code{stdout()} if the session is
interactive and there are no sinks, otherwise it will select \code{stderr()}.}

\item{expr}{R expression to evaluate.}
}
\description{
This only works in terminal emulators. In other environments, it
does nothing.
}
\details{
\code{ansi_hide_cursor()} hides the cursor.

\code{ansi_show_cursor()} shows the cursor.

\code{ansi_with_hidden_cursor()} temporarily hides the cursor for
evaluating an expression.
}
\seealso{
Other terminal capabilities: 
\code{\link{is_ansi_tty}()},
\code{\link{is_dynamic_tty}()}

Other low level ANSI functions: 
\code{\link{ansi_has_any}()},
\code{\link{ansi_regex}()},
\code{\link{ansi_string}()},
\code{\link{ansi_strip}()}
}
\concept{low level ANSI functions}
\concept{terminal capabilities}
