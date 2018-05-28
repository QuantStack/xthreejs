#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xraw_shader_material>;
template xw::xmaterialize<xthree::xraw_shader_material>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xraw_shader_material>>;
template class xw::xgenerator<xthree::xraw_shader_material>;
template xw::xgenerator<xthree::xraw_shader_material>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xraw_shader_material>>;