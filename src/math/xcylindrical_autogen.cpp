#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcylindrical>;
template xw::xmaterialize<xthree::xcylindrical>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcylindrical>>;
template class xw::xgenerator<xthree::xcylindrical>;
template xw::xgenerator<xthree::xcylindrical>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcylindrical>>;