#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlight>;
template xw::xmaterialize<xthree::xlight>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlight>>;
template class xw::xgenerator<xthree::xlight>;
template xw::xgenerator<xthree::xlight>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlight>>;