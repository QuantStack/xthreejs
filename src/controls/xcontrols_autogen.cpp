#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcontrols>;
template xw::xmaterialize<xthree::xcontrols>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcontrols>>;
template class xw::xgenerator<xthree::xcontrols>;
template xw::xgenerator<xthree::xcontrols>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcontrols>>;