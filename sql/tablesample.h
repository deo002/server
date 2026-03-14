#ifndef TABLESAMPLE_INCLUDED
#define TABLESAMPLE_INCLUDED

#include "sql_alloc.h"

class THD;
class Item;

enum enum_tablesample_type
{
  TABLESAMPLE_UNDEF= 0,
  TABLESAMPLE_SYSTEM,
  TABLESAMPLE_BERNOULLI
};

class Lex_tablesample: public Sql_alloc
{
private:
  enum_tablesample_type tablesample_type;
  Item *tablesample_percentage;
  double percentage;
public:
  Lex_tablesample(enum_tablesample_type m, Item *p)
    : tablesample_type(m), tablesample_percentage(p), percentage(0.0) {}

  bool fix_and_set_tablesample_percentage(THD *thd);

  double get_sampling_percentage() const
  {
    return percentage;
  }

  enum_tablesample_type get_sampling_type() const
  {
    return tablesample_type;
  }
};

#endif