#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xbone>;
template xw::xmaterialize<xthree::xbone>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xbone>>;
template class xw::xgenerator<xthree::xbone>;
template xw::xgenerator<xthree::xbone>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xbone>>;