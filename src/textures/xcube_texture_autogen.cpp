#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcube_texture>;
template xw::xmaterialize<xthree::xcube_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcube_texture>>;
template class xw::xgenerator<xthree::xcube_texture>;
template xw::xgenerator<xthree::xcube_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcube_texture>>;