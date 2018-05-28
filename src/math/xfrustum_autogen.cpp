#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfrustum>;
template xw::xmaterialize<xthree::xfrustum>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfrustum>>;
template class xw::xgenerator<xthree::xfrustum>;
template xw::xgenerator<xthree::xfrustum>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfrustum>>;