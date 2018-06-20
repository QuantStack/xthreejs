#ifndef XTHREE_LOADING_MANAGER_HPP
#define XTHREE_LOADING_MANAGER_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // loading_manager declaration
    //

    template<class D>
    class xloading_manager : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xloading_manager();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using loading_manager = xw::xmaterialize<xloading_manager>;

    using loading_manager_generator = xw::xgenerator<xloading_manager>;

    //
    // loading_manager implementation
    //


    template <class D>
    inline void xloading_manager<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xloading_manager<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xloading_manager<D>::xloading_manager()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xloading_manager<D>::set_defaults()
    {
        this->_model_name() = "LoadingManagerModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xloading_manager>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xloading_manager>;
        extern template xw::xmaterialize<xthree::xloading_manager>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xloading_manager>>;
        extern template class xw::xgenerator<xthree::xloading_manager>;
        extern template xw::xgenerator<xthree::xloading_manager>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xloading_manager>>;
    #endif
#endif

#endif