#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xvideo_texture>;
template xw::xmaterialize<xthree::xvideo_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xvideo_texture>>;
template class xw::xgenerator<xthree::xvideo_texture>;
template xw::xgenerator<xthree::xvideo_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xvideo_texture>>;