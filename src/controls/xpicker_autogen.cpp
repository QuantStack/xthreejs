#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpicker>;
template xw::xmaterialize<xthree::xpicker>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpicker>>;
template class xw::xgenerator<xthree::xpicker>;
template xw::xgenerator<xthree::xpicker>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpicker>>;