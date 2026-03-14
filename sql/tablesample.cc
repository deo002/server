#include "my_global.h"
#include "tablesample.h"
#include "item.h"
#include "sql_error.h"

bool Lex_tablesample::fix_and_set_tablesample_percentage(THD *thd)
{
  if (!tablesample_percentage->fixed() && 
      tablesample_percentage->fix_fields(thd, &tablesample_percentage)) {
          my_error(ER_ILLEGAL_TABLESAMPLE_PERCENTAGE, MYF(0));
          return TRUE;
  }
  percentage= tablesample_percentage->val_real();
  if (percentage < 0.0 || percentage > 100.0) {
      my_error(ER_ILLEGAL_TABLESAMPLE_PERCENTAGE, MYF(0));
      return TRUE;
  }
  return FALSE;
}