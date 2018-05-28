#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtext_texture>;
template xw::xmaterialize<xthree::xtext_texture>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtext_texture>>;
template class xw::xgenerator<xthree::xtext_texture>;
template xw::xgenerator<xthree::xtext_texture>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtext_texture>>;