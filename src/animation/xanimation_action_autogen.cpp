#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_action_base>;
template xw::xmaterialize<xthree::xanimation_action_base>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_action_base>>;
template class xw::xgenerator<xthree::xanimation_action_base>;
template xw::xgenerator<xthree::xanimation_action_base>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_action_base>>;