#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_extensions>;
template xw::xmaterialize<xthree::xwebgl_extensions>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_extensions>>;
template class xw::xgenerator<xthree::xwebgl_extensions>;
template xw::xgenerator<xthree::xwebgl_extensions>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_extensions>>;