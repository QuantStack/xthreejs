#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_programs>;
template xw::xmaterialize<xthree::xwebgl_programs>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_programs>>;
template class xw::xgenerator<xthree::xwebgl_programs>;
template xw::xgenerator<xthree::xwebgl_programs>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_programs>>;