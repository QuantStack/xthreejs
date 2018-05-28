#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_capabilities>;
template xw::xmaterialize<xthree::xwebgl_capabilities>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_capabilities>>;
template class xw::xgenerator<xthree::xwebgl_capabilities>;
template xw::xgenerator<xthree::xwebgl_capabilities>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_capabilities>>;