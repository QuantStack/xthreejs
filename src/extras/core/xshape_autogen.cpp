#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshape>;
template xw::xmaterialize<xthree::xshape>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshape>>;
template class xw::xgenerator<xthree::xshape>;
template xw::xgenerator<xthree::xshape>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshape>>;