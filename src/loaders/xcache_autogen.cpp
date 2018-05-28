#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcache>;
template xw::xmaterialize<xthree::xcache>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcache>>;
template class xw::xgenerator<xthree::xcache>;
template xw::xgenerator<xthree::xcache>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcache>>;