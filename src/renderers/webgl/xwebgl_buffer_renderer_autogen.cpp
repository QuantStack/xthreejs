#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_buffer_renderer>;
template xw::xmaterialize<xthree::xwebgl_buffer_renderer>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_buffer_renderer>>;
template class xw::xgenerator<xthree::xwebgl_buffer_renderer>;
template xw::xgenerator<xthree::xwebgl_buffer_renderer>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_buffer_renderer>>;