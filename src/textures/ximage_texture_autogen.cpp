#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::ximage_texture>;
template xw::xmaterialize<xthree::ximage_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::ximage_texture>>;
template class xw::xgenerator<xthree::ximage_texture>;
template xw::xgenerator<xthree::ximage_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::ximage_texture>>;