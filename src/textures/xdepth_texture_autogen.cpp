#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdepth_texture>;
template xw::xmaterialize<xthree::xdepth_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdepth_texture>>;
template class xw::xgenerator<xthree::xdepth_texture>;
template xw::xgenerator<xthree::xdepth_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdepth_texture>>;