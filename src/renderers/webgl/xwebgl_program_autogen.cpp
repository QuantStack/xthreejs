#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_program>;
template xw::xmaterialize<xthree::xwebgl_program>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_program>>;
template class xw::xgenerator<xthree::xwebgl_program>;
template xw::xgenerator<xthree::xwebgl_program>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_program>>;