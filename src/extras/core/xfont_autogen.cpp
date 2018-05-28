#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfont>;
template xw::xmaterialize<xthree::xfont>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfont>>;
template class xw::xgenerator<xthree::xfont>;
template xw::xgenerator<xthree::xfont>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfont>>;