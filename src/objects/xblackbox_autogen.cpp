#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xblackbox>;
template xw::xmaterialize<xthree::xblackbox>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xblackbox>>;
template class xw::xgenerator<xthree::xblackbox>;
template xw::xgenerator<xthree::xblackbox>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xblackbox>>;