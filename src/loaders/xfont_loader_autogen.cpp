#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfont_loader>;
template xw::xmaterialize<xthree::xfont_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfont_loader>>;
template class xw::xgenerator<xthree::xfont_loader>;
template xw::xgenerator<xthree::xfont_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfont_loader>>;