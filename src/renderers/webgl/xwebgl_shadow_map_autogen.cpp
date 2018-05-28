#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_shadow_map_base>;
template xw::xmaterialize<xthree::xwebgl_shadow_map_base>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_shadow_map_base>>;
template class xw::xgenerator<xthree::xwebgl_shadow_map_base>;
template xw::xgenerator<xthree::xwebgl_shadow_map_base>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_shadow_map_base>>;