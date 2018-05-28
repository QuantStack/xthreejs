#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_lights>;
template xw::xmaterialize<xthree::xwebgl_lights>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_lights>>;
template class xw::xgenerator<xthree::xwebgl_lights>;
template xw::xgenerator<xthree::xwebgl_lights>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_lights>>;