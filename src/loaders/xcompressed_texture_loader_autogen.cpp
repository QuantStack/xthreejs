#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcompressed_texture_loader>;
template xw::xmaterialize<xthree::xcompressed_texture_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcompressed_texture_loader>>;
template class xw::xgenerator<xthree::xcompressed_texture_loader>;
template xw::xgenerator<xthree::xcompressed_texture_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcompressed_texture_loader>>;