% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/ansiex.R
\name{ansi_simplify}
\alias{ansi_simplify}
\title{Simplify ANSI styling tags}
\usage{
ansi_simplify(x, csi = c("keep", "drop"))
}
\arguments{
\item{x}{Input string}

\item{csi}{What to do with non-SGR ANSI sequences, either \code{"keep"},
or \code{"drop"} them.}
}
\value{
Simplified \code{cli_ansi_string} vector.
}
\description{
It creates an equivalent, but possibly shorter ANSI styled string, by
removing duplicate and empty tags.
}
