#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdata_texture>;
template xw::xmaterialize<xthree::xdata_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdata_texture>>;
template class xw::xgenerator<xthree::xdata_texture>;
template xw::xgenerator<xthree::xdata_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdata_texture>>;