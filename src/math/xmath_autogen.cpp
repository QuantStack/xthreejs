#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xmath>;
template xw::xmaterialize<xthree::xmath>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xmath>>;
template class xw::xgenerator<xthree::xmath>;
template xw::xgenerator<xthree::xmath>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xmath>>;