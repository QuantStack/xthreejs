#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpositional_audio>;
template xw::xmaterialize<xthree::xpositional_audio>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpositional_audio>>;
template class xw::xgenerator<xthree::xpositional_audio>;
template xw::xgenerator<xthree::xpositional_audio>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpositional_audio>>;