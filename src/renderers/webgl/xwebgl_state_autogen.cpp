#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_state>;
template xw::xmaterialize<xthree::xwebgl_state>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_state>>;
template class xw::xgenerator<xthree::xwebgl_state>;
template xw::xgenerator<xthree::xwebgl_state>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_state>>;