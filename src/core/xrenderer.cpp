#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xrenderer>;
template xw::xmaterialize<xthree::xrenderer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xrenderer>>;
template class xw::xgenerator<xthree::xrenderer>;
template xw::xgenerator<xthree::xrenderer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xrenderer>>;