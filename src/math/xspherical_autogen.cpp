#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xspherical>;
template xw::xmaterialize<xthree::xspherical>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xspherical>>;
template class xw::xgenerator<xthree::xspherical>;
template xw::xgenerator<xthree::xspherical>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xspherical>>;