#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xlight_shadow>;
template xw::xmaterialize<xthree::xlight_shadow>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xlight_shadow>>;
template class xw::xgenerator<xthree::xlight_shadow>;
template xw::xgenerator<xthree::xlight_shadow>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xlight_shadow>>;