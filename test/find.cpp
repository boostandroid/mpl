//-----------------------------------------------------------------------------
// boost mpl/test/find.cpp source file
// See http://www.boost.org for updates, documentation, and revision history.
//-----------------------------------------------------------------------------
//
// Copyright (c) 2000-01
// Aleksey Gurtovoy
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee, 
// provided that the above copyright notice appears in all copies and 
// that both the copyright notice and this permission notice appear in 
// supporting documentation. No representations are made about the 
// suitability of this software for any purpose. It is provided "as is" 
// without express or implied warranty.

#include "boost/mpl/find.hpp"
#include "boost/mpl/type_list.hpp"
#include "boost/mpl/value_list.hpp"
#include "boost/mpl/distance.hpp"
#include "boost/mpl/begin_end.hpp"
#include "boost/mpl/int_t.hpp"
#include "boost/mpl/assert_is_same.hpp"
#include "boost/static_assert.hpp"

namespace mpl = boost::mpl;

int main()
{    
    typedef mpl::type_list<int,char,long,short,char,long,double,long> types;
    typedef mpl::value_list<1,0,5,1,7,5,0,5> values;

    typedef mpl::find<types, short> types_find;
    typedef mpl::find< values, mpl::int_t<7> > values_find;
    
    BOOST_MPL_ASSERT_IS_SAME(types_find::iterator::type, short);
    BOOST_STATIC_ASSERT(values_find::iterator::value == 7);

    typedef mpl::begin<types>::iterator types_first;
    typedef mpl::begin<values>::iterator values_first;
    BOOST_STATIC_ASSERT((mpl::distance< types_first, types_find::iterator >::value == 3));
    BOOST_STATIC_ASSERT((mpl::distance< values_first, values_find::iterator >::value == 4));
    
    return 0;
}
