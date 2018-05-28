#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::ximage_loader>;
template xw::xmaterialize<xthree::ximage_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::ximage_loader>>;
template class xw::xgenerator<xthree::ximage_loader>;
template xw::xgenerator<xthree::ximage_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::ximage_loader>>;