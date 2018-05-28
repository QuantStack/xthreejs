#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcompressed_texture>;
template xw::xmaterialize<xthree::xcompressed_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcompressed_texture>>;
template class xw::xgenerator<xthree::xcompressed_texture>;
template xw::xgenerator<xthree::xcompressed_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcompressed_texture>>;