#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtriangle>;
template xw::xmaterialize<xthree::xtriangle>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtriangle>>;
template class xw::xgenerator<xthree::xtriangle>;
template xw::xgenerator<xthree::xtriangle>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtriangle>>;