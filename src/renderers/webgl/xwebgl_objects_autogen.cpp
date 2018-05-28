#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_objects>;
template xw::xmaterialize<xthree::xwebgl_objects>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_objects>>;
template class xw::xgenerator<xthree::xwebgl_objects>;
template xw::xgenerator<xthree::xwebgl_objects>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_objects>>;