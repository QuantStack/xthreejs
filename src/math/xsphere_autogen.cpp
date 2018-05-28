#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xsphere>;
template xw::xmaterialize<xthree::xsphere>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xsphere>>;
template class xw::xgenerator<xthree::xsphere>;
template xw::xgenerator<xthree::xsphere>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xsphere>>;