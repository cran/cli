
#include "cli.h"
#include "cleancall.h"

#include <R_ext/Rdynload.h>
#include <Rversion.h>

SEXP clic_unload() {
  clic_stop_thread();
  return R_NilValue;
}

SEXP clic_dataptr(SEXP x);

#ifdef GCOV_COMPILE

void __gcov_flush();
SEXP clic__gcov_flush() {
  __gcov_flush();
  return R_NilValue;
}

#else

SEXP clic__gcov_flush() {
  return R_NilValue;
}

#endif

static const R_CallMethodDef callMethods[]  = {
  CLEANCALL_METHOD_RECORD,

  { "clic_tty_size",       (DL_FUNC) clic_tty_size,       0 },

  { "clic_dataptr",        (DL_FUNC) clic_dataptr,        1 },
  { "clic_start_thread",   (DL_FUNC) clic_start_thread,   3 },
  { "clic_stop_thread",    (DL_FUNC) clic_stop_thread,    0 },
  { "clic_tick_reset",     (DL_FUNC) clic_tick_reset,     0 },
  { "clic_tick_set",       (DL_FUNC) clic_tick_set,       2 },
  { "clic_tick_pause",     (DL_FUNC) clic_tick_pause,     1 },
  { "clic_tick_resume",    (DL_FUNC) clic_tick_resume,    1 },
  { "clic_unload",         (DL_FUNC) clic_unload,         0 },
  { "clic_get_time",       (DL_FUNC) clic_get_time,       0 },
  { "clic_make_timer",     (DL_FUNC) clic_make_timer,     0 },
  { "clic_update_due",     (DL_FUNC) clic_update_due,     0 },

  { "clic_progress_along", (DL_FUNC) clic_progress_along, 2 },

  { "clic__find_var",      (DL_FUNC) clic__find_var,      2 },
  { "clic__gcov_flush",    (DL_FUNC) clic__gcov_flush,    0 },

  { "clic_get_embedded_utf8", (DL_FUNC) clic_get_embedded_utf8, 0 },
  { "clic_set_embedded_utf8", (DL_FUNC) clic_set_embedded_utf8, 1 },

  { NULL, NULL, 0 }
};

#define RCC(fun) R_RegisterCCallable("cli", # fun, (DL_FUNC) fun);

void R_init_cli(DllInfo *dll) {
#if R_VERSION >= R_Version(3, 5, 0)
  cli_init_altrep(dll);
#endif

  R_registerRoutines(dll, NULL, callMethods, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
  R_forceSymbols(dll, TRUE);

  cleancall_fns_dot_call = Rf_findVar(Rf_install(".Call"), R_BaseEnv);

  RCC(cli_progress_add);
  RCC(cli_progress_bar);
  RCC(cli_progress_done);
  RCC(cli_progress_init_timer);
  RCC(cli_progress_num);
  RCC(cli_progress_set);
  RCC(cli_progress_set_clear);
  RCC(cli_progress_set_format);
  RCC(cli_progress_set_name);
  RCC(cli_progress_set_status);
  RCC(cli_progress_set_type);
  RCC(cli_progress_update);
  RCC(cli_progress_sleep);
}
