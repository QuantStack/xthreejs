#ifndef XTHREE_LINE3_HPP
#define XTHREE_LINE3_HPP

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
    // line3 declaration
    //

    template<class D>
    class xline3 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, start, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, end, vector3({0,0,0}));


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xline3();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line3 = xw::xmaterialize<xline3>;

    using line3_generator = xw::xgenerator<xline3>;

    //
    // line3 implementation
    //


    template <class D>
    inline void xline3<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(start, state, buffers);
        xw::set_patch_from_property(end, state, buffers);
    }

    template <class D>
    inline void xline3<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(start, patch, buffers);
        xw::set_property_from_patch(end, patch, buffers);
    }

    template <class D>
    inline xline3<D>::xline3()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline3<D>::set_defaults()
    {
        this->_model_name() = "Line3Model";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xline3>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xline3>;
        extern template xw::xmaterialize<xthree::xline3>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xline3>>;
        extern template class xw::xgenerator<xthree::xline3>;
        extern template xw::xgenerator<xthree::xline3>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xline3>>;
    #endif
#endif

#endif