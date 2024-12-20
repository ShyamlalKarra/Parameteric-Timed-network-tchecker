// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   ppyylex



#include "program.tab.hh"


// Unqualified %code blocks.
#line 45 "program.yy"

  // Declare the lexer for the parser's sake.
  tchecker::parsing::program::parser_t::symbol_type ppyylex
  (std::string const & program_context,
  std::shared_ptr<tchecker::expression_t> & expr,
  std::shared_ptr<tchecker::statement_t> & stmt);
  
  
  // Global variables
  static unsigned int old_error_count;
  
  
  // Fake expression used is case of syntax error to allow parsing of the
  // entire expression
  class fake_expression_t final : public tchecker::lvalue_expression_t {
  public:
    virtual ~fake_expression_t() = default;
    virtual std::ostream & output(std::ostream & os) const override { return os; }
    virtual fake_expression_t * clone() const override { return new fake_expression_t(); }
    virtual void visit(tchecker::expression_visitor_t & v) const override {}
  };

  auto fake_expression = std::make_shared<fake_expression_t>();
  
  // Fake variable expression used is case of syntax error to allow parsing of
  // the entire expression
  class fake_var_expression_t final : public tchecker::var_expression_t {
  public:
    fake_var_expression_t() : tchecker::var_expression_t("tck__") {}
    virtual ~fake_var_expression_t() = default;
    virtual std::ostream & output(std::ostream & os) const override { return os; }
    virtual fake_var_expression_t * clone() const override { return new fake_var_expression_t(); }
    virtual void visit(tchecker::expression_visitor_t & v) const override {}
  };
  
  auto fake_var_expression = std::make_shared<fake_var_expression_t>();
  
  // Fake statement used in case of syntax error to allow parsing of the
  // entire statement
  class fake_statement_t final : public tchecker::statement_t {
  public:
    virtual ~fake_statement_t() = default;
    virtual std::ostream & output(std::ostream & os) const override { return os; }
    virtual fake_statement_t * clone() const override { return new fake_statement_t(); }
    virtual void visit(tchecker::statement_visitor_t & v) const override {}
  };

  auto fake_statement = std::make_shared<fake_statement_t>();

#line 98 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if PPYYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !PPYYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !PPYYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 13 "program.yy"
namespace tchecker { namespace parsing { namespace program {
#line 191 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"

  /// Build a parser object.
  parser_t::parser_t (std::string const & program_context_yyarg, std::shared_ptr<tchecker::expression_t> & expr_yyarg, std::shared_ptr<tchecker::statement_t> & stmt_yyarg)
#if PPYYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      program_context (program_context_yyarg),
      expr (expr_yyarg),
      stmt (stmt_yyarg)
  {}

  parser_t::~parser_t ()
  {}

  parser_t::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser_t::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser_t::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser_t::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser_t::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser_t::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser_t::symbol_kind_type
  parser_t::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser_t::stack_symbol_type::stack_symbol_type ()
  {}

  parser_t::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.YY_MOVE_OR_COPY< enum tchecker::binary_operator_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_binary_formula: // binary_formula
      case symbol_kind::S_term: // term
        value.YY_MOVE_OR_COPY< std::shared_ptr<tchecker::expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.YY_MOVE_OR_COPY< std::shared_ptr<tchecker::lvalue_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< std::shared_ptr<tchecker::statement_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.YY_MOVE_OR_COPY< std::shared_ptr<tchecker::var_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.YY_MOVE_OR_COPY< tchecker::integer_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser_t::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.move< enum tchecker::binary_operator_t > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_binary_formula: // binary_formula
      case symbol_kind::S_term: // term
        value.move< std::shared_ptr<tchecker::expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.move< std::shared_ptr<tchecker::lvalue_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.move< std::shared_ptr<tchecker::statement_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.move< std::shared_ptr<tchecker::var_expression_t> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser_t::stack_symbol_type&
  parser_t::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.copy< enum tchecker::binary_operator_t > (that.value);
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_binary_formula: // binary_formula
      case symbol_kind::S_term: // term
        value.copy< std::shared_ptr<tchecker::expression_t> > (that.value);
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.copy< std::shared_ptr<tchecker::lvalue_expression_t> > (that.value);
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.copy< std::shared_ptr<tchecker::statement_t> > (that.value);
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.copy< std::shared_ptr<tchecker::var_expression_t> > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.copy< tchecker::integer_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser_t::stack_symbol_type&
  parser_t::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        value.move< enum tchecker::binary_operator_t > (that.value);
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_binary_formula: // binary_formula
      case symbol_kind::S_term: // term
        value.move< std::shared_ptr<tchecker::expression_t> > (that.value);
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        value.move< std::shared_ptr<tchecker::lvalue_expression_t> > (that.value);
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        value.move< std::shared_ptr<tchecker::statement_t> > (that.value);
        break;

      case symbol_kind::S_variable_term: // variable_term
        value.move< std::shared_ptr<tchecker::var_expression_t> > (that.value);
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_integer: // integer
        value.move< tchecker::integer_t > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser_t::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if PPYYDEBUG
  template <typename Base>
  void
  parser_t::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_TOK_ID: // "identifier"
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 504 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_TOK_INTEGER: // "integer"
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::string > (); }
#line 510 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::statement_t> > ()->output(yyoutput); }
#line 516 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_statement: // statement
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::statement_t> > ()->output(yyoutput); }
#line 522 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_if_statement: // if_statement
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::shared_ptr<tchecker::statement_t> > (); }
#line 528 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_loop_statement: // loop_statement
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::shared_ptr<tchecker::statement_t> > (); }
#line 534 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_local_statement: // local_statement
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::shared_ptr<tchecker::statement_t> > (); }
#line 540 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_simple_statement: // simple_statement
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::shared_ptr<tchecker::statement_t> > (); }
#line 546 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_assignment: // assignment
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::statement_t> > ()->output(yyoutput); }
#line 552 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::expression_t> > ()->output(yyoutput); }
#line 558 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::expression_t> > ()->output(yyoutput); }
#line 564 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_atomic_formula: // atomic_formula
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::expression_t> > ()->output(yyoutput); }
#line 570 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_predicate_formula: // predicate_formula
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::expression_t> > ()->output(yyoutput); }
#line 576 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_binary_formula: // binary_formula
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < std::shared_ptr<tchecker::expression_t> > (); }
#line 582 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_predicate_operator: // predicate_operator
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < enum tchecker::binary_operator_t > (); }
#line 588 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_term: // term
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::expression_t> > ()->output(yyoutput); }
#line 594 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::lvalue_expression_t> > ()->output(yyoutput); }
#line 600 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_variable_term: // variable_term
#line 165 "program.yy"
                 { yysym.value.template as < std::shared_ptr<tchecker::var_expression_t> > ()->output(yyoutput); }
#line 606 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      case symbol_kind::S_integer: // integer
#line 164 "program.yy"
                 { yyoutput << yysym.value.template as < tchecker::integer_t > (); }
#line 612 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  parser_t::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser_t::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser_t::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if PPYYDEBUG
  std::ostream&
  parser_t::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser_t::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser_t::debug_level_type
  parser_t::debug_level () const
  {
    return yydebug_;
  }

  void
  parser_t::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // PPYYDEBUG

  parser_t::state_type
  parser_t::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser_t::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser_t::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser_t::operator() ()
  {
    return parse ();
  }

  int
  parser_t::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    // User initialization code.
#line 96 "program.yy"
{
  old_error_count = tchecker::log_error_count();
}

#line 736 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (program_context, expr, stmt));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_predicate_operator: // predicate_operator
        yylhs.value.emplace< enum tchecker::binary_operator_t > ();
        break;

      case symbol_kind::S_conjunctive_formula: // conjunctive_formula
      case symbol_kind::S_non_atomic_conjunctive_formula: // non_atomic_conjunctive_formula
      case symbol_kind::S_atomic_formula: // atomic_formula
      case symbol_kind::S_predicate_formula: // predicate_formula
      case symbol_kind::S_binary_formula: // binary_formula
      case symbol_kind::S_term: // term
        yylhs.value.emplace< std::shared_ptr<tchecker::expression_t> > ();
        break;

      case symbol_kind::S_lvalue_term: // lvalue_term
        yylhs.value.emplace< std::shared_ptr<tchecker::lvalue_expression_t> > ();
        break;

      case symbol_kind::S_sequence_statement: // sequence_statement
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_if_statement: // if_statement
      case symbol_kind::S_loop_statement: // loop_statement
      case symbol_kind::S_local_statement: // local_statement
      case symbol_kind::S_simple_statement: // simple_statement
      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< std::shared_ptr<tchecker::statement_t> > ();
        break;

      case symbol_kind::S_variable_term: // variable_term
        yylhs.value.emplace< std::shared_ptr<tchecker::var_expression_t> > ();
        break;

      case symbol_kind::S_TOK_ID: // "identifier"
      case symbol_kind::S_TOK_INTEGER: // "integer"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_integer: // integer
        yylhs.value.emplace< tchecker::integer_t > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: sequence_statement
#line 184 "program.yy"
{ expr = nullptr;
  if (tchecker::log_error_count() > old_error_count)
    stmt = nullptr;
  else
    stmt = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > ();
}
#line 919 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 3: // program: conjunctive_formula
#line 191 "program.yy"
{
  if (tchecker::log_error_count() > old_error_count)
    expr = nullptr;
  else
    expr = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ();
  stmt = nullptr;
}
#line 931 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 6: // sequence_statement: statement opt_semicolon
#line 207 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[1].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 937 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 7: // sequence_statement: statement ";" sequence_statement
#line 209 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::sequence_statement_t>(yystack_[2].value.as < std::shared_ptr<tchecker::statement_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = fake_statement;
  }
}
#line 951 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 8: // statement: simple_statement
#line 222 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 957 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 9: // statement: if_statement
#line 224 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 963 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 10: // statement: loop_statement
#line 226 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 969 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 11: // if_statement: "if" conjunctive_formula "then" sequence_statement "end"
#line 231 "program.yy"
    {  yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::if_statement_t>(yystack_[3].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::statement_t> > (), std::make_shared<tchecker::nop_statement_t>()); }
#line 975 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 12: // if_statement: "if" conjunctive_formula "then" sequence_statement "else" sequence_statement "end"
#line 233 "program.yy"
    {  yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::if_statement_t>(yystack_[5].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[3].value.as < std::shared_ptr<tchecker::statement_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::statement_t> > ()); }
#line 981 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 13: // loop_statement: "while" conjunctive_formula "do" sequence_statement "end"
#line 238 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::while_statement_t>(yystack_[3].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::statement_t> > ()); }
#line 987 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 14: // local_statement: "local" variable_term
#line 243 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::local_var_statement_t>(yystack_[0].value.as < std::shared_ptr<tchecker::var_expression_t> > ()); }
#line 993 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 15: // local_statement: "local" variable_term "=" term
#line 245 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::local_var_statement_t>(yystack_[2].value.as < std::shared_ptr<tchecker::var_expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ()); }
#line 999 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 16: // local_statement: "local" variable_term "[" term "]"
#line 247 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::local_array_statement_t>(yystack_[3].value.as < std::shared_ptr<tchecker::var_expression_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ()); }
#line 1005 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 17: // simple_statement: assignment
#line 252 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 1011 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 18: // simple_statement: "nop"
#line 254 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::nop_statement_t>(); }
#line 1017 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 19: // simple_statement: local_statement
#line 256 "program.yy"
    { yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::statement_t> > (); }
#line 1023 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 20: // assignment: lvalue_term "=" term
#line 262 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = std::make_shared<tchecker::assign_statement_t>(yystack_[2].value.as < std::shared_ptr<tchecker::lvalue_expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::statement_t> > () = fake_statement;
  }
}
#line 1037 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 21: // conjunctive_formula: atomic_formula
#line 276 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > (); }
#line 1043 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 22: // conjunctive_formula: non_atomic_conjunctive_formula
#line 278 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > (); }
#line 1049 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 23: // non_atomic_conjunctive_formula: "(" non_atomic_conjunctive_formula ")"
#line 284 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::par_expression_t>(yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1063 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 24: // non_atomic_conjunctive_formula: atomic_formula "&&" conjunctive_formula
#line 294 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_LAND, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1077 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 25: // atomic_formula: term
#line 308 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > (); }
#line 1083 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 26: // atomic_formula: predicate_formula
#line 310 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > (); }
#line 1089 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 27: // atomic_formula: "!" atomic_formula
#line 312 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::unary_expression_t>(tchecker::EXPR_OP_LNOT, yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1103 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 28: // predicate_formula: "(" predicate_formula ")"
#line 326 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::par_expression_t>(yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1117 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 29: // predicate_formula: binary_formula predicate_operator term
#line 336 "program.yy"
{
  try {
    auto left = std::dynamic_pointer_cast<tchecker::binary_expression_t>(yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > ());
    if (! tchecker::is_less(left->binary_operator()) || ! tchecker::is_less(yystack_[1].value.as < enum tchecker::binary_operator_t > ())) {
      tchecker::parsing::program::parser_t::error(yylhs.location, "Only < and <= are allowed in combined expressions");
      yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
    }
    else {
      std::shared_ptr<tchecker::expression_t> middle_clone{left->right_operand().clone()};
      auto right = std::make_shared<tchecker::binary_expression_t>(yystack_[1].value.as < enum tchecker::binary_operator_t > (), middle_clone, yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
      yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_LAND, left, right);
    }
  } 
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1140 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 30: // predicate_formula: binary_formula
#line 355 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > (); }
#line 1146 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 31: // binary_formula: term predicate_operator term
#line 361 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(yystack_[1].value.as < enum tchecker::binary_operator_t > (), yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1160 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 32: // predicate_operator: "=="
#line 374 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_EQ; }
#line 1166 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 33: // predicate_operator: "!="
#line 375 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_NEQ; }
#line 1172 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 34: // predicate_operator: "<"
#line 376 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LT; }
#line 1178 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 35: // predicate_operator: "<="
#line 377 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_LE; }
#line 1184 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 36: // predicate_operator: ">="
#line 378 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GE; }
#line 1190 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 37: // predicate_operator: ">"
#line 379 "program.yy"
          { yylhs.value.as < enum tchecker::binary_operator_t > () = tchecker::EXPR_OP_GT; }
#line 1196 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 38: // term: integer
#line 385 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::int_expression_t>(yystack_[0].value.as < tchecker::integer_t > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1210 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 39: // term: lvalue_term
#line 395 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::lvalue_expression_t> > (); }
#line 1216 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 40: // term: "(" term ")"
#line 397 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::par_expression_t>(yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1230 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 41: // term: "-" term
#line 407 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::unary_expression_t>(tchecker::EXPR_OP_NEG, yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1244 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 42: // term: term "+" term
#line 417 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_PLUS, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1258 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 43: // term: term "-" term
#line 427 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_MINUS, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1272 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 44: // term: term "*" term
#line 437 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_TIMES, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1286 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 45: // term: term "/" term
#line 447 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_DIV, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1300 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 46: // term: term "%" term
#line 457 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::binary_expression_t>(tchecker::EXPR_OP_MOD, yystack_[2].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[0].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1314 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 47: // term: "(" "if" conjunctive_formula "then" term "else" term ")"
#line 467 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = std::make_shared<tchecker::ite_expression_t>(yystack_[5].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[3].value.as < std::shared_ptr<tchecker::expression_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::expression_t> > () = fake_expression;
  }
}
#line 1328 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 48: // lvalue_term: variable_term
#line 481 "program.yy"
{ yylhs.value.as < std::shared_ptr<tchecker::lvalue_expression_t> > () = yystack_[0].value.as < std::shared_ptr<tchecker::var_expression_t> > (); }
#line 1334 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 49: // lvalue_term: variable_term "[" term "]"
#line 483 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::lvalue_expression_t> > () = std::make_shared<tchecker::array_expression_t>(yystack_[3].value.as < std::shared_ptr<tchecker::var_expression_t> > (), yystack_[1].value.as < std::shared_ptr<tchecker::expression_t> > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::lvalue_expression_t> > () = fake_expression;
  }
}
#line 1348 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 50: // variable_term: "identifier"
#line 497 "program.yy"
{
  try {
    yylhs.value.as < std::shared_ptr<tchecker::var_expression_t> > () = std::make_shared<tchecker::var_expression_t>(yystack_[0].value.as < std::string > ());
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yylhs.location << " " << e.what() << std::endl;
    yylhs.value.as < std::shared_ptr<tchecker::var_expression_t> > () = fake_var_expression;
  }
}
#line 1362 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;

  case 51: // integer: "integer"
#line 511 "program.yy"
{
  try {
    long long l = std::stoll(yystack_[0].value.as < std::string > (), nullptr, 10);
    if ( (l < std::numeric_limits<integer_t>::min()) || (l > std::numeric_limits<integer_t>::max()) )
      throw std::out_of_range("");
    yylhs.value.as < tchecker::integer_t > () = static_cast<tchecker::integer_t>(l);
  }
  catch (std::exception const & e) {
    std::cerr << tchecker::log_error << yystack_[0].location << " value " << yystack_[0].value.as < std::string > () << " out of range ";
    std::cerr << std::numeric_limits<integer_t>::min() << "," << std::numeric_limits<integer_t>::max() << std::endl;
    yylhs.value.as < tchecker::integer_t > () = 0;
  }
}
#line 1380 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"
    break;


#line 1384 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser_t::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser_t::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser_t::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser_t::context.
  parser_t::context::context (const parser_t& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser_t::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser_t::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser_t::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser_t::yypact_ninf_ = -32;

  const signed char parser_t::yytable_ninf_ = -1;

  const short
  parser_t::yypact_[] =
  {
      56,    -2,    15,     7,    11,    11,   -32,   -23,   -32,   -32,
      18,   -32,    16,   -32,   -32,   -32,   -32,   -32,   -32,   -32,
       9,   -32,   157,   119,    27,    33,   -32,    11,    42,     9,
      43,    96,   -32,    69,   -32,    73,   -32,    34,    45,     6,
     -32,    68,   -32,    11,   -32,   -32,   -32,   -32,   -32,   -32,
      15,    15,    15,    15,    15,    15,    15,    15,    15,    64,
     -32,   -32,   -32,   136,    43,    96,    68,    68,    15,    15,
     -32,    27,   -32,    52,    63,    63,   -32,   -32,   -32,    52,
      52,   152,    15,    -9,    57,    52,   159,   -32,   109,   -32,
      68,   -32,   -32,    15,    66,   145,   -32,   -32
  };

  const signed char
  parser_t::yydefact_[] =
  {
       0,     0,     0,     0,     0,     0,    18,     0,    50,    51,
       0,     2,     5,     9,    10,    19,     8,    17,     3,    22,
      21,    26,    30,    25,    39,    48,    38,     0,     0,     0,
      26,    25,    39,     0,    41,     0,    27,     0,     0,    14,
       1,     4,     6,     0,    32,    33,    35,    36,    34,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,    28,    40,     0,     0,     0,     0,     0,     0,     0,
       7,     0,    24,    29,    42,    43,    44,    45,    46,    31,
      20,     0,     0,     0,     0,    15,     0,    49,     0,    11,
       0,    13,    16,     0,     0,     0,    12,    47
  };

  const signed char
  parser_t::yypgoto_[] =
  {
     -32,   -32,   -32,   -31,   -32,   -32,   -32,   -32,   -32,   -32,
       0,   101,    30,     5,   -32,    88,    -1,     3,   104,   -32
  };

  const signed char
  parser_t::yydefgoto_[] =
  {
       0,    10,    42,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    56,    23,    32,    25,    26
  };

  const signed char
  parser_t::yytable_[] =
  {
      31,    34,     1,    24,    37,    38,    30,     8,     2,    68,
      70,    35,    69,     3,    89,     1,    90,     2,    40,    33,
      27,     2,     3,    43,    41,     2,     3,    59,     8,     9,
      57,    29,    63,    36,    65,    83,    84,     8,     9,    58,
      64,     8,     9,    72,    71,     8,     9,    60,    61,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    66,    94,
       1,    51,    52,    53,    54,    55,     2,    85,    86,    71,
      71,     3,    67,    33,    53,    54,    55,    35,     4,     2,
      91,    88,     5,     2,     6,     7,     8,     9,    82,    96,
       4,    27,    95,    71,     5,    27,     6,     7,     8,     8,
       9,    62,    28,     8,     9,    51,    52,    53,    54,    55,
      50,    39,    44,    45,    46,    47,    48,    49,    51,    52,
      53,    54,    55,     0,     0,     0,     0,     0,    51,    52,
      53,    54,    55,     0,    93,    44,    45,    46,    47,    48,
      49,    62,     0,     0,     0,    51,    52,    53,    54,    55,
      97,     0,     0,     0,    51,    52,    53,    54,    55,    87,
       0,    51,    52,    53,    54,    55,    92,     0,    51,    52,
      53,    54,    55,    44,    45,    46,    47,    48,    49
  };

  const signed char
  parser_t::yycheck_[] =
  {
       1,     2,     4,     0,     4,     5,     1,    30,    10,     3,
      41,     4,     6,    15,    23,     4,    25,    10,     0,     4,
      22,    10,    15,    14,     8,    10,    15,    27,    30,    31,
       3,     1,    33,     3,    35,    66,    67,    30,    31,     6,
      35,    30,    31,    43,    41,    30,    31,     5,     5,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    24,    90,
       4,     9,    10,    11,    12,    13,    10,    68,    69,    66,
      67,    15,    27,     4,    11,    12,    13,     4,    22,    10,
      23,    82,    26,    10,    28,    29,    30,    31,    24,    23,
      22,    22,    93,    90,    26,    22,    28,    29,    30,    30,
      31,     5,     1,    30,    31,     9,    10,    11,    12,    13,
      22,     7,    16,    17,    18,    19,    20,    21,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    -1,    -1,     9,    10,
      11,    12,    13,    -1,    25,    16,    17,    18,    19,    20,
      21,     5,    -1,    -1,    -1,     9,    10,    11,    12,    13,
       5,    -1,    -1,    -1,     9,    10,    11,    12,    13,     7,
      -1,     9,    10,    11,    12,    13,     7,    -1,     9,    10,
      11,    12,    13,    16,    17,    18,    19,    20,    21
  };

  const signed char
  parser_t::yystos_[] =
  {
       0,     4,    10,    15,    22,    26,    28,    29,    30,    31,
      34,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    49,    50,    51,    52,    22,    44,    45,
      46,    49,    50,     4,    49,     4,    45,    43,    43,    51,
       0,     8,    35,    14,    16,    17,    18,    19,    20,    21,
      48,     9,    10,    11,    12,    13,    48,     3,     6,    43,
       5,     5,     5,    49,    46,    49,    24,    27,     3,     6,
      36,    50,    43,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    24,    36,    36,    49,    49,     7,    49,    23,
      25,    23,     7,    25,    36,    49,    23,     5
  };

  const signed char
  parser_t::yyr1_[] =
  {
       0,    33,    34,    34,    35,    35,    36,    36,    37,    37,
      37,    38,    38,    39,    40,    40,    40,    41,    41,    41,
      42,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    47,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
      51,    52
  };

  const signed char
  parser_t::yyr2_[] =
  {
       0,     2,     1,     1,     1,     0,     2,     3,     1,     1,
       1,     5,     7,     5,     2,     4,     5,     1,     1,     1,
       3,     1,     1,     3,     3,     1,     1,     2,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     3,     3,     3,     3,     3,     8,     1,     4,
       1,     1
  };


#if PPYYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser_t::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\"=\"", "\"(\"",
  "\")\"", "\"[\"", "\"]\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"%\"", "\"&&\"", "\"!\"", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"",
  "\"<\"", "\">\"", "\"if\"", "\"end\"", "\"then\"", "\"else\"",
  "\"while\"", "\"do\"", "\"nop\"", "\"local\"", "\"identifier\"",
  "\"integer\"", "UMINUS", "$accept", "program", "opt_semicolon",
  "sequence_statement", "statement", "if_statement", "loop_statement",
  "local_statement", "simple_statement", "assignment",
  "conjunctive_formula", "non_atomic_conjunctive_formula",
  "atomic_formula", "predicate_formula", "binary_formula",
  "predicate_operator", "term", "lvalue_term", "variable_term", "integer", YY_NULLPTR
  };
#endif


#if PPYYDEBUG
  const short
  parser_t::yyrline_[] =
  {
       0,   183,   183,   190,   201,   202,   206,   208,   221,   223,
     225,   230,   232,   237,   242,   244,   246,   251,   253,   255,
     261,   275,   277,   283,   293,   307,   309,   311,   325,   335,
     354,   360,   374,   375,   376,   377,   378,   379,   384,   394,
     396,   406,   416,   426,   436,   446,   456,   466,   480,   482,
     496,   510
  };

  void
  parser_t::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser_t::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // PPYYDEBUG


#line 13 "program.yy"
} } } // tchecker::parsing::program
#line 1931 "/Users/shyamkarra/Desktop/Parametric-Git-Repos/PV-of-General-DTN/cegar/cegar-Implementation/tchecker-runner/tchecker-edited/build/src/parsing/program_parser/program.tab.cc"

#line 527 "program.yy"



void tchecker::parsing::program::parser_t::error(location_type const & l, std::string const & msg)
{
  if (program_context.empty())
    std::cerr << tchecker::log_error << l << " " << msg << std::endl;
  else
    std::cerr << tchecker::log_error << program_context << " " << msg << " (at " << l << ")" << std::endl;
}
